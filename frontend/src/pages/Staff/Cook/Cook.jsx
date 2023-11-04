import React, { useEffect, useState } from 'react';

import {
  Box,
  List,
  Button,
  Typography,
  Divider,
  Dialog,
  DialogTitle,
  DialogContent,
  DialogContentText,
  DialogActions,
  ListItem,
  ListItemText,
  LinearProgress
} from '@mui/material';

import CookList from './CookList';
import Instructions from './Instructions';

import data from '../../../data/data.json';

function Cook() {
  const { requiredIngredients, ingredients } = data;

  const [socket, setSocket] = useState(null);
  const [pot, setPot] = useState([]);
  const [progress, setProgress] = useState(0);
  const [open, setOpen] = useState(false);
  const [cooking, setCooking] = useState(false);
  const [isCooked, setIsCooked] = useState(false);
  const [orders, setOrders] = useState([]);
  const [selectedOrder, setSelectedOrder] = useState(null);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('S-Cook');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'S-Cook left');
      }
    };
  }, []);

  useEffect(() => {
    let timer = null;

    if (cooking) {
      timer = setInterval(() => {
        setProgress((oldProgress) => {
          if (oldProgress === 100) {
            clearInterval(timer);
            return 100;
          }

          const newProgress = oldProgress + 100 / 30;

          return newProgress;
        });
      }, 1000);
    } else {
      setProgress(0);
    }
    return () => {
      clearInterval(timer);
    };
  }, [cooking]);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const { type, data } = JSON.parse(event.data);
        if (type === 'cook-order') {
          setOrders((prevOrders) => [...prevOrders, data]);
        }
      };
    }
  }, [socket]);

  const selectOrder = (order) => {
    setSelectedOrder(order);
  };

  const addToPot = (ingredient) => {
    setPot((prevPot) => [...prevPot, ingredient]);
  };

  const removeFromPot = (ingredient) => {
    setPot((prevPot) => prevPot.filter((item) => item !== ingredient));
  };

  function handleOKClick() {
    setOpen(false);
  }

  const cook = () => {
    let sortedIngredients = [];

    for (let item of selectedOrder.food) {
      const food = requiredIngredients.find((food) => food.name === item.name);

      if (food) {
        sortedIngredients = [...sortedIngredients, ...food.ingredients];
      }
    }

    sortedIngredients.sort();

    const sortedPot = [...pot].sort();

    if (JSON.stringify(sortedPot) === JSON.stringify(sortedIngredients)) {
      setCooking(true);
      setTimeout(() => {
        setCooking(false);
        setIsCooked(true);
      }, 30000);
    } else {
      setOpen(true);
    }
  };

  const sendOrder = () => {
    setPot([]);
    setIsCooked(false);
    setSelectedOrder(null);

    setOrders((prevOrders) =>
      prevOrders.filter((order) => order !== selectedOrder)
    );

    if (socket) {
      socket.send(JSON.stringify({ type: 'serve-order', data: selectedOrder }));
    }
  };

  return (
    <Box
      sx={{
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <Typography variant='h1'>Cook</Typography>

      <CookList orders={orders} selectOrder={selectOrder} />

      {selectedOrder && <Instructions order={selectedOrder} />}

      <Box
        sx={{
          width: '60%',
          display: 'flex',
          textAlign: 'center'
        }}
      >
        <Box
          sx={{
            m: 2,
            p: 2,
            width: '100%',
            borderRadius: '4px',
            border: '4px solid',
            justifyContent: 'center',
            borderColor: 'primary.main'
          }}
        >
          <Typography variant='h3'>Ingredients</Typography>

          <Divider sx={{ my: 2 }} />

          <List>
            {ingredients.map((ingredient, index) => (
              <ListItem key={index}>
                <ListItemText
                  primary={ingredient}
                  sx={{ textAlign: 'center' }}
                />

                <Button
                  size='small'
                  variant='contained'
                  onClick={() => addToPot(ingredient)}
                >
                  Add
                </Button>
              </ListItem>
            ))}
          </List>
        </Box>

        <Box
          sx={{
            m: 2,
            p: 2,
            width: '100%',
            borderRadius: '4px',
            border: '4px solid',
            justifyContent: 'center',
            borderColor: 'primary.main'
          }}
        >
          <Typography variant='h3'>Pot</Typography>

          <Divider sx={{ my: 2 }} />

          <List>
            {pot.map((ingredient, index) => (
              <ListItem key={index}>
                <ListItemText
                  primary={ingredient}
                  sx={{ textAlign: 'center' }}
                />
                <Button
                  size='small'
                  variant='outlined'
                  onClick={() => removeFromPot(ingredient)}
                >
                  Remove
                </Button>
              </ListItem>
            ))}
          </List>

          {cooking ? (
            <LinearProgress variant='determinate' value={progress} />
          ) : (
            <Button
              color='primary'
              variant='contained'
              onClick={isCooked ? sendOrder : cook}
            >
              {isCooked ? 'Send to Customer' : 'Cook'}
            </Button>
          )}

          {cooking && <Typography variant='h6'>Cooking...</Typography>}
        </Box>
      </Box>

      <Dialog open={open}>
        <DialogTitle>Incorrect Ingredients</DialogTitle>
        <DialogContent>
          <DialogContentText>
            You do not have the correct ingredients to cook this order.
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={handleOKClick}>OK</Button>
        </DialogActions>
      </Dialog>
    </Box>
  );
}

export default Cook;
