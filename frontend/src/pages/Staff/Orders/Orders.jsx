import React, { useState, createContext, useEffect } from 'react';

import { Box, Typography } from '@mui/material';

import OrderList from './OrderList';

export const OrdersContext = createContext();

function Orders({ socket }) {
  const [newOrders, setNewOrders] = useState([]);
  const [cookingOrders, setCookingOrders] = useState([]);
  const [completedOrders, setCompletedOrders] = useState([]);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const { type, order } = JSON.parse(event.data);
        if (type === 'make-order') {
          setNewOrders((prevOrders) => [...prevOrders, order]);
        }
      };
    }
  }, [socket]);

  const handleCookClick = (order) => {
    setNewOrders((prevOrders) =>
      prevOrders.filter((o) => o.title !== order.title)
    );

    setCookingOrders((prevOrders) => [...prevOrders, order]);

    if (socket) {
      socket.send(JSON.stringify({ type: 'cook-order', received: 'yes' }));
    }
  };

  return (
    <OrdersContext.Provider value={{ handleCookClick }}>
      <Box
        sx={{
          display: 'flex',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <Typography variant='h1' sx={{ m: 2 }}>
          Orders
        </Typography>

        <OrderList type='New' orders={newOrders} />
        <OrderList type='Cooking' orders={cookingOrders} />
        <OrderList type='Completed' orders={completedOrders} />
      </Box>
    </OrdersContext.Provider>
  );
}

export default Orders;
