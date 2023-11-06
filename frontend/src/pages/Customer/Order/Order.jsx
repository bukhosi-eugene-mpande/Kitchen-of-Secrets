import React, { useState, createContext, useEffect, useContext } from 'react';

import { CustomerContext } from '../Customer';

import {
  Box,
  Button,
  Dialog,
  Typography,
  DialogTitle,
  DialogContent,
  DialogActions,
  DialogContentText
} from '@mui/material';

import Menu from './Menu';
import OrderList from './OrderList';

export const OrderContext = createContext();

function Order() {
  const randomTable = Math.floor(Math.random() * 6) + 1;

  const [order, setOrder] = useState({
    food: [],
    beverages: [],
    table: randomTable
  });
  
  const [open, setOpen] = useState(false);
  const [socket, setSocket] = useState(null);
  const { changeTab } = useContext(CustomerContext);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('C-Order');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'C-Order left');
      }
    };
  }, []);

  useEffect(() => {
    if (socket) {
      socket.onmessage = handleReceived;

      return () => {
        socket.onmessage = null;
      };
    }
  }, [socket]);

  function addToOrder(item, category) {
    setOrder((prevOrder) => {
      const newOrder = { ...prevOrder };
      newOrder[category].push(item);
      return newOrder;
    });
  }

  function removeFromOrder(index, category) {
    setOrder((prevOrder) => {
      const newOrder = { ...prevOrder };
      newOrder[category].splice(index, 1);
      return newOrder;
    });
  }

  const handleReceived = (event) => {
    const { type, data } = JSON.parse(event.data);
    if (type === 'receive-order') {
      if (data.received === 'yes') {
        setOpen(true);
      }
    }
  };

  function handleOKClick() {
    setOpen(false);
    changeTab(null, 2);
  }

  return (
    <OrderContext.Provider value={{ order, addToOrder, removeFromOrder }}>
      <Box
        sx={{ 
        backgroundImage: `url('./assets/OrderExBackground.png')`,
        backgroundSize: 'cover',
        backgroundPosition: 'top',
        backgroundRepeat: 'no-repeat',
          display: 'flex',
          textAlign: 'center',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <Typography variant='h1' sx={{ m: 2 ,color: 'white',
        fontFamily: 'Gloria Hallelujah, cursive',
        fontWeight: 700}}>
          Order
        </Typography>

        <Box
          sx={{
            width: '100%',
            display: 'flex',
            justifyContent: 'center'
          }}
        >
          <Menu />
          <OrderList socket={socket} />
        </Box>
        <Dialog open={open}>
          <DialogTitle>Order Received</DialogTitle>
          <DialogContent>
            <DialogContentText>
              Your order is now being prepared. Please Wait.
            </DialogContentText>
          </DialogContent>
          <DialogActions>
            <Button onClick={handleOKClick}>OK</Button>
          </DialogActions>
        </Dialog>
      </Box>
    </OrderContext.Provider>
  );
}

export default Order;
