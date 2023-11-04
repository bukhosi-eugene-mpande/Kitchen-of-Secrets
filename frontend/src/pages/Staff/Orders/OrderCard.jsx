import React from 'react';

import LoadingButton from '@mui/lab/LoadingButton';
import { Box, Card, Divider, CardContent, CardActions, Typography } from '@mui/material';

function OrderCard({ order, type, cookOrder }) {
  return (
    <Box sx={{ m: 2 }}>
      <Card variant='outlined' sx={{ width: 200 }}>
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

        <CardActions>
          <LoadingButton
            size='small'
            variant='contained'
            onClick={() => cookOrder(order)}
            loading={type === 'Cooking' ? true : false}
            disabled={type === 'Completed' ? true : false}
          >
            {type === 'Completed' ? 'Cooked' : 'Cook'}
          </LoadingButton>
        </CardActions>
      </Card>
    </Box>
  );
}

export default OrderCard;
