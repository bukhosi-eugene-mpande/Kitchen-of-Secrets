import React, { useState } from 'react';

import { Box, Tab, Tabs } from '@mui/material';
import { CalendarToday, Restaurant, Payments, TableRestaurant } from '@mui/icons-material';

import Order from './Order';
import Payment from './Payment';
import Reservation from './Reservation';
import Table from './Table';
import Panel from '../../components/Panel';

function Customer() {
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
          <Tab
            icon={<CalendarToday />}
            label='Reservation'
            sx={{ width: '100%' }}
          />
          <Tab icon={<Restaurant />} label='Order' sx={{ width: '100%' }} />
          <Tab icon={<Payments />} label='Payment' sx={{ width: '100%' }} />
          <Tab icon={<TableRestaurant />} label='Table' sx={{ width: '100%' }} /> {/*should this be labeled Table or Restaurant ? if customer can only see their table*/}
        </Tabs>
      </Box>

      <Panel value={value} index={0}>
        <Reservation />
      </Panel>

      <Panel value={value} index={1}>
        <Order />
      </Panel>

      <Panel value={value} index={2}>
        <Payment />
      </Panel>

      <Panel value={value} index={3}>
        <Table />
      </Panel>
    </Box>
  );
}

export default Customer;
