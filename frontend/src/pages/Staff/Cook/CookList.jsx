import React, { useContext } from 'react';

import CookCard from './CookCard';

import { CookContext } from './Cook';

import { Box, Typography } from '@mui/material';

function CookList() {
  const { orders, selectOrder } = useContext(CookContext);

  return (
    <Box
      sx={{
        m: 2,
        p: 2,
        width: '60%',
        border: '4px solid',
        borderRadius: '4px',
        borderColor: 'primary.main',
        backgroundColor: 'rgba(0, 0, 0, 0.7)'
      }}
    >
      <Typography variant='h4'>New Orders</Typography>

      <Box sx={{ display: 'flex', overflow: 'scroll' }}>
        {orders.map((order, index) => (
          <CookCard key={index} order={order} selectOrder={selectOrder} />
        ))}
      </Box>
    </Box>
  );
}

export default CookList;
