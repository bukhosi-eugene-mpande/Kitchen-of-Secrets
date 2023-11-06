import React, { useState, useEffect } from 'react';

import { Box, Typography } from '@mui/material';

import OrderList from './OrderList';

function Orders() {
  const [socket, setSocket] = useState(null);

  const [newOrders, setNewOrders] = useState([]);
  const [cookingOrders, setCookingOrders] = useState([]);
  const [completedOrders, setCompletedOrders] = useState([]);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('S-Order');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'S-Order left');
      }
    };
  }, []);

  useEffect(() => {
    if (socket) {
      socket.onmessage = receiveOrder;

      return () => {
        socket.onmessage = null;
      };
    }
  }, [socket]);

  const receiveOrder = (event) => {
    const { type, data } = JSON.parse(event.data);

    if (type === 'make-order') {
      setNewOrders((prevOrders) => [...prevOrders, data.order]);
    }
  };

  const cookOrder = (order) => {
    setNewOrders((prevOrders) => {
      const index = prevOrders.findIndex((o) => o.title === order.title);

      if (index !== -1) {
        prevOrders.splice(index, 1);
      }
      
      return [...prevOrders];
    });

    setCookingOrders((prevOrders) => [...prevOrders, order]);

    if (socket) {
      socket.send(
        JSON.stringify({ type: 'receive-order', data: { received: 'yes' } })
      );

      socket.send(JSON.stringify({ type: 'cook-order', data: order }));
    }
  };

  return (
    <Box
      sx={{
        backgroundImage: `url('./assets/OrderExBackground.png')`,
        backgroundSize: 'cover',
        backgroundPosition: 'top',
        backgroundRepeat: 'no-repeat',
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <Typography variant='h1' sx={{ m: 2 }}>
        Orders
      </Typography>

      <OrderList type='New' orders={newOrders} cookOrder={cookOrder} />
      <OrderList type='Cooking' orders={cookingOrders} />
      <OrderList type='Completed' orders={completedOrders} />
    </Box>
  );
}

export default Orders;
