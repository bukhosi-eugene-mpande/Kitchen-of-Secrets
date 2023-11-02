import React from 'react';

import { Box, Card, CardContent, CardActions, Typography } from '@mui/material';

import LoadingButton from '@mui/lab/LoadingButton';

function OrderCard({ order, type, onClick }) {
  return (
    <Box sx={{ m: 2 }}>
      <Card variant='outlined' sx={{ width: 200 }}>
        <CardContent>
          <Typography variant='h5' component='div'>
            {order.title}
          </Typography>
          <Typography variant='body2'>{order.foodItems}</Typography>
          <Typography variant='body2'>{order.drink}</Typography>
        </CardContent>

        <CardActions>
          <LoadingButton
            size='small'
            variant='contained'
            onClick={() => onClick(order)}
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
