import React from 'react';
import { Box, Typography } from '@mui/material';

import OrderList from './OrderList';

function Orders() {
  const newOrders = [
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
    {
      title: 'Order 3',
      foodItems: ['Steak', 'Fries'],
      drink: 'Wine'
    },
    {
      title: 'Order 4',
      foodItems: ['Chicken', 'Rice'],
      drink: 'Soda'
    },
    {
      title: 'Order 5',
      foodItems: ['Fish', 'Chips'],
      drink: 'Beer'
    },
    {
      title: 'Order 5',
      foodItems: ['Fish', 'Chips'],
      drink: 'Beer'
    },
    {
      title: 'Order 4',
      foodItems: ['Chicken', 'Rice'],
      drink: 'Soda'
    },
    {
      title: 'Order 5',
      foodItems: ['Fish', 'Chips'],
      drink: 'Beer'
    },
    {
      title: 'Order 5',
      foodItems: ['Fish', 'Chips'],
      drink: 'Beer'
    }
  ];

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

      <OrderList type='New' orders={newOrders} />
      <OrderList type='Cooking' orders={newOrders} />
      <OrderList type='Completed' orders={newOrders} />

    </Box>
  );
}

export default Orders;
