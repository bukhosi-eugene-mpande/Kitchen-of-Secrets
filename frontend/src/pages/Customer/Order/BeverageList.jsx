import React, { useContext } from 'react';

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

function BeverageList() {
  const { addToOrder } = useContext(OrderContext);

  const beverages = [
    { name: 'Coke', price: 2 },
    { name: 'Water', price: 1 },
    { name: 'Juice', price: 3 },
    { name: 'Coffee', price: 4 },
    { name: 'Tea', price: 2 }
  ];

  return (
    <Box
      sx={{
        p: 2,
        m: 2,
        width: '100%',
        border: '2px solid',
        borderRadius: '4px',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h4' sx={{ m: 2 }}>
        Beverages
      </Typography>

      <Divider />

      <List>
        {beverages.map((item, index) => (
          <ListItem key={index}>
            <ListItemText primary={`${item.name} - R${item.price}`} />
            <Button variant='contained' onClick={() => addToOrder(item)}>
              Add
            </Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default BeverageList;
