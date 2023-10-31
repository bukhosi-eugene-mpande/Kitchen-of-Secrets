import React, { useState } from 'react';

import { Box, Typography } from '@mui/material';

import Menu from './Menu';
import OrderList from './OrderList';

function Order() {
  const [order, setOrder] = useState([]);

  function addToOrder(item) {
    setOrder([...order, item]);
  }

  function removeFromOrder(index) {
    const newOrder = [...order];

    newOrder.splice(index, 1);
    setOrder(newOrder);
  }

  return (
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
        <Menu addToOrder={addToOrder} />
        <OrderList order={order} removeFromOrder={removeFromOrder} />
      </Box>
    </Box>
  );
}

export default Order;
