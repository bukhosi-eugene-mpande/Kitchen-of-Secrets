import React from 'react';

import OrderCard from './OrderCard';

import { Box, Typography } from '@mui/material';

function OrderList({ type, orders, cookOrder }) {
  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '60%',
        border: '4px solid',
        borderRadius: '4px',
        borderColor: 'primary.main',
        backgroundColor: 'rgba(0, 0, 0, 0.7)',
        padding: '20px',
        borderRadius: '10px'
      }}
    >
      <Typography variant='h4'>{type}</Typography>

      <Box sx={{ display: 'flex', overflow: 'scroll' }}>
        {orders.map((order, index) => (
          <OrderCard
            key={index}
            type={type}
            order={order}
            cookOrder={cookOrder}
          />
        ))}
      </Box>
    </Box>
  );
}

export default OrderList;
