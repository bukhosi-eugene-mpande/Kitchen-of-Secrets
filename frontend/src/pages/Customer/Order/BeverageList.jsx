import React, { useContext } from 'react';

import { OrderContext } from './Order';

import data from '../../../data/data.json';

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
  const { beverageMenu } = data;
  const { addToOrder } = useContext(OrderContext);

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
        {beverageMenu.map((item, index) => (
          <ListItem key={index}>
            <ListItemText primary={`${item.name} - R${item.price}`} />
            <Button
              variant='contained'
              onClick={() => addToOrder(item, 'beverages')}
            >
              Add
            </Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default BeverageList;
