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

function Order({socket}) {
  const [order, setOrder] = useState([]);
  const [open, setOpen] = useState(false);
  const { changeTab } = useContext(CustomerContext);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const data = JSON.parse(event.data);
        if (data.received === 'yes') {
          setOpen(true);
        }
      };
    }
  }, [socket]);

  function addToOrder(item) {
    setOrder([...order, item]);
  }

  function removeFromOrder(index) {
    const newOrder = [...order];
    newOrder.splice(index, 1);
    setOrder(newOrder);
  }

  function handleOKClick() {
    setOpen(false);
    changeTab(null, 2);
  }

  return (
    <OrderContext.Provider value={{ order, addToOrder, removeFromOrder }}>
      <Box
        sx={{
          display: 'flex',
          textAlign: 'center',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <Typography variant='h1' sx={{ m: 2 }}>
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
