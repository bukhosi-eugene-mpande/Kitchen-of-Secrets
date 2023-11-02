import React from 'react';

import OrderCard from './OrderCard';

import { Box, Typography } from '@mui/material';

function OrderList({ type, orders, onCook }) {
  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '60%',
        border: '4px solid',
        borderRadius: '4px',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h4'>{type}</Typography>

      <Box sx={{ display: 'flex', overflow: 'scroll' }}>
        {orders.map((order) => (
          <OrderCard order={order} type={type} onClick={onCook} />
        ))}
      </Box>
    </Box>
  );
}

export default OrderList;
