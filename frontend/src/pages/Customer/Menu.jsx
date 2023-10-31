import React from 'react';

import { Box, Typography } from '@mui/material';

import FoodList from './FoodList';
import BeverageList from './BeverageList';

function Menu({ addToOrder }) {
  return (
    <Box>
      <Typography variant='h3' sx={{ m: 2 }}>
        Menu
      </Typography>

      <Box
        sx={{
          display: 'flex',
          alignItems: 'center',
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
