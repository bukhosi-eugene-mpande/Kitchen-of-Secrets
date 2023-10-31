import React from 'react';

import {
  Box,
  List,
  Button,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function FoodList({ addToOrder }) {
  const food = ['Pizza', 'Burger', 'Pasta'];

  return (
    <Box>
      <Typography variant='h4' sx={{ m: 2 }}>
        Food
      </Typography>

      <List>
        {food.map((item, index) => (
          <ListItem key={index}>
            <ListItemText primary={item} />
            <Button onClick={() => addToOrder(item)}>Add</Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default FoodList;
