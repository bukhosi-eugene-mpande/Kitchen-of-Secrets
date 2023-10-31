import React from 'react';

import { Box, Divider, Typography } from '@mui/material';

import FoodList from './FoodList';
import BeverageList from './BeverageList';

function Menu({ addToOrder }) {
  return (
    <Box
      sx={{
        p: 2,
        m: 2,
        width: '50%',
        border: '2px solid',
        borderRadius: '4px',
        borderColor: 'primary.main'
      }}
    >
      <Typography variant='h3' sx={{ m: 2 }}>
        Menu
      </Typography>

      <Divider />

      <Box
        sx={{
          display: 'flex',
          justifyContent: 'center'
        }}
      >
        <FoodList addToOrder={addToOrder} />
        <BeverageList addToOrder={addToOrder} />
      </Box>
    </Box>
  );
}

export default Menu;
