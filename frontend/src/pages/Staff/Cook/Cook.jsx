import React, { useEffect, useState, createContext } from 'react';

import {
  Box,
  Button,
  Typography,
  Dialog,
  DialogTitle,
  DialogContent,
  DialogContentText,
  DialogActions
} from '@mui/material';

import Pot from './Pot';
import CookList from './CookList';
import Ingredients from './Ingredients';
import Instructions from './Instructions';

export const CookContext = createContext();

function Cook() {
  const [socket, setSocket] = useState(null);
  const [pot, setPot] = useState([]);
  const [open, setOpen] = useState(false);
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
    <CookContext.Provider
      value={{
        pot,
        orders,
        addToPot,
        isCooked,
        sendOrder,
        setIsCooked,
        selectOrder,
        selectedOrder,
        removeFromPot
      }}
    >
      <Box
        sx={{
          backgroundImage: `url('./assets/cook.png')`,
          backgroundSize: 'cover',
          backgroundPosition: 'center',
          backgroundRepeat: 'no-repeat',
          minHeight: '100vh',
          display: 'flex',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <Typography variant='h1'>Cook</Typography>

        <CookList />

        {selectedOrder && <Instructions order={selectedOrder} />}

        <Box
          sx={{
            width: '60%',
            display: 'flex',
            textAlign: 'center'
          }}
        >
          <Ingredients />
          <Pot />
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
    </CookContext.Provider>
  );
}

export default Cook;
