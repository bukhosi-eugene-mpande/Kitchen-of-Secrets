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

import LoadingButton from '@mui/lab/LoadingButton';

import CookList from './CookList';
import Instructions from './Instructions';

import data from '../../../data/data.json';

function Cook() {
  const { mockOrders, ingredients } = data;

  const [pot, setPot] = useState([]);
  const [progress, setProgress] = useState(0);
  const [open, setOpen] = useState(false);
  const [cooking, setCooking] = useState(false);
  const [isCooked, setIsCooked] = useState(false);
  const [orders, setOrders] = useState(mockOrders);
  const [selectedOrder, setSelectedOrder] = useState(mockOrders[0]);

  const socket = new WebSocket('ws://your-websocket-url');

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
    socket.onmessage = (event) => {
      const receivedOrder = JSON.parse(event.data);
      setOrders((prevOrders) => [...prevOrders, receivedOrder]);
    };
  }, []);

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
    const sortedPot = [...pot].sort();
    const sortedIngredients = [...ingredients].sort();

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
    //socket.send(JSON.stringify(selectedOrder));
    setIsCooked(false);
    setSelectedOrder({});
    setOrders((prevOrders) =>
      prevOrders.filter((order) => order !== selectedOrder)
    );
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
