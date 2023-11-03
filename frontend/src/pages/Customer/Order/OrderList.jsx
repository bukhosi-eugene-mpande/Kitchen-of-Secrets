import React, { useContext, useState } from 'react';

import { OrderContext } from './Order';

import {
  Box,
  List,
  Button,
  Divider,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

import LoadingButton from '@mui/lab/LoadingButton';

function OrderList({ socket }) {
  const [loading, setLoading] = useState(false);
  const { order, removeFromOrder } = useContext(OrderContext);

  const totalPrice = order.reduce((total, item) => total + item.price, 0);

  function handleOrderClick() {
    setLoading(true);

    if (socket) {
      socket.send(JSON.stringify({ type: 'make-order', data: { order } }));
    }
  }

  return (
    <Box
      sx={{
        p: 2,
        m: 2,
        width: '30%',
        border: '2px solid',
        borderRadius: '4px',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h3' sx={{ m: 2 }}>
        Order
      </Typography>

      <Divider />

      <Box
        sx={{
          p: 2,
          mt: 2,
          width: '100%',
          border: '2px solid',
          borderRadius: '4px',
          borderColor: 'primary.main'
        }}
      >
        <Typography variant='h4' sx={{ m: 2 }}>
          Items
        </Typography>

        <Divider />

        <List>
          {order.map((item, index) => (
            <ListItem key={index}>
              <ListItemText primary={`${item.name} - R${item.price}`} />
              <Button variant='outlined' onClick={() => removeFromOrder(index)}>
                Remove
              </Button>
            </ListItem>
          ))}
        </List>

        <Typography variant='h6' sx={{ m: 2 }}>
          Total: R{totalPrice}
        </Typography>
      </Box>

      <LoadingButton
        size='large'
        sx={{ m: 2 }}
        color='primary'
        loading={loading}
        variant='contained'
        onClick={handleOrderClick}
      >
        Order
      </LoadingButton>
    </Box>
  );
}

export default OrderList;
