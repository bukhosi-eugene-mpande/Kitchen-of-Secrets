import React, { useState } from 'react';

import { Box, Tab, Tabs } from '@mui/material';
import { Payments, TableRestaurant } from '@mui/icons-material';

import Restaurant from './Restaurant';
import PrivateRestaurant from './PrivateRestaurant';
import BuyIngredients from './BuyIngredients';
import Panel from '../../components/Panel';

function Staff() {
  const [value, setValue] = useState(0);

  const handleChange = (event, newValue) => {
    setValue(newValue);
  };

  return (
    <Box>
      <Box
        sx={{
          borderBottom: 1,
          borderColor: 'divider'
        }}
      >
        <Tabs value={value} onChange={handleChange}>
          <Tab icon={<TableRestaurant />} label='General Section' sx={{ width: '100%' }} /> 
          <Tab icon={<TableRestaurant />} label='Private Section' sx={{ width: '100%' }} /> 
          <Tab icon={<Payments />} label='Buy Ingredients' sx={{ width: '100%' }} />
        </Tabs>
      </Box>

      <Panel value={value} index={0}>
        <Restaurant />
      </Panel>

      <Panel value={value} index={1}>
        <PrivateRestaurant />
      </Panel>

      <Panel value={value} index={2}>
        <BuyIngredients />
      </Panel>

    </Box>
  );
}

export default Staff;
