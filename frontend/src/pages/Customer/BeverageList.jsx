import React from 'react';

import {
  Box,
  List,
  Button,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function BeverageList({ addToOrder }) {
  const beverages = ['Coke', 'Water', 'Juice'];

  return (
    <Box>
      <Typography variant='h4' sx={{ m: 2 }}>
        Beverages
      </Typography>

      <List>
        {beverages.map((item, index) => (
          <ListItem key={index}>
            <ListItemText primary={item} />
            <Button onClick={() => addToOrder(item)}>Add</Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default BeverageList;
