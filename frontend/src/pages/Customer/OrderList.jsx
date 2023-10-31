import React from 'react';

import {
  Box,
  List,
  Button,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function OrderList({ order, removeFromOrder }) {
  return (
    <Box>
      <Typography variant='h3' sx={{ m: 2 }}>
        Order
      </Typography>

      <Box>
        <Typography variant='h4' sx={{ m: 2 }}>
          Items
        </Typography>

        <List>
          {order.map((item, index) => (
            <ListItem key={index}>
              <ListItemText primary={item} />
              <Button onClick={() => removeFromOrder(index)}>Remove</Button>
            </ListItem>
          ))}
        </List>
      </Box>
    </Box>
  );
}

export default OrderList;
