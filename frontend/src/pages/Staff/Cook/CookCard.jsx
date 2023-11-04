import React from 'react';

import { Box, Card, Divider, CardContent, Typography } from '@mui/material';

function CookCard({ order, selectOrder }) {
  return (
    <Box sx={{ m: 2 }}>
      <Card
        variant='outlined'
        sx={{ width: 200 }}
        onClick={() => selectOrder(order)}
      >
        <CardContent>
          <Typography variant='h5'>Table: {order.table}</Typography>

          <Divider sx={{ my: 1 }} />

          <Typography variant='h6'>Food:</Typography>
          {order.food.map((item, index) => (
            <Typography key={index} variant='body2'>
              {item.name}
            </Typography>
          ))}

          <br />

          <Typography variant='h6'>Beverages:</Typography>
          {order.beverages.map((item, index) => (
            <Typography key={index} variant='body2'>
              {item.name}
            </Typography>
          ))}
        </CardContent>
      </Card>
    </Box>
  );
}

export default CookCard;
