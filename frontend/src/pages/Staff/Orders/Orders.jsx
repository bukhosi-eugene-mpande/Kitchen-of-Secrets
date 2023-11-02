import React, { useState } from 'react';
import { Box, Typography } from '@mui/material';

import OrderList from './OrderList';

function Orders() {
  const initialOrders = [
    {
      title: 'Order 1',
      foodItems: ['Pizza', 'Burger'],
      drink: 'Coke'
    },
    {
      title: 'Order 2',
      foodItems: ['Pasta', 'Salad'],
      drink: 'Water'
    },
    // ...rest of your orders
  ];

  const [newOrders, setNewOrders] = useState(initialOrders);
  const [cookingOrders, setCookingOrders] = useState([]);
  const [completedOrders, setCompletedOrders] = useState([]);

  const handleCook = (order) => {
    setNewOrders(prevOrders => prevOrders.filter(o => o.title !== order.title));
    setCookingOrders(prevOrders => [...prevOrders, order]);
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
      <Typography variant='h1' sx={{ m: 2 }}>
        Orders
      </Typography>

      <OrderList type='New' orders={newOrders} onCook={handleCook} />
      <OrderList type='Cooking' orders={cookingOrders} />
      <OrderList type='Completed' orders={completedOrders} />

    </Box>
  );
}

export default Orders;