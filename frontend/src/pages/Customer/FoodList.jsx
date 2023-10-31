import React from 'react';
import {
  Box,
  List,
  Button,
  Divider,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function FoodList({ addToOrder }) {
  const food = [
    { name: 'Pizza', price: 10 },
    { name: 'Burger', price: 15 },
    { name: 'Pasta', price: 12 },
    { name: 'Salad', price: 8 },
    { name: 'Soup', price: 7 }
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
        Food
      </Typography>

      <Divider />

      <List>
        {food.map((item, index) => (
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

export default FoodList;
