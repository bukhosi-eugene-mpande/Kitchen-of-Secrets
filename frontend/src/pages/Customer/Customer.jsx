import React, { useState, createContext } from 'react';

import { Box, Tab, Tabs } from '@mui/material';

import {
  MenuBook,
  PointOfSale,
  DinnerDining,
  CalendarToday,
  TableRestaurant
} from '@mui/icons-material';

import Eat from './Eat/Eat';
import Order from './Order/Order';
import Payment from './Payment/Payment';
import Table from './Table';
import Panel from '../../components/Panel';
import Reservation from './Reservation/Reservation';

export const CustomerContext = createContext();

const Customer = () => {
  const [value, setValue] = useState(0);

  const changeTab = (event, newValue) => {
    setValue(newValue);
  };

  return (
    <CustomerContext.Provider value={{ changeTab }}>
      <Box>
        <Box
          sx={{
            borderBottom: 1,
            borderColor: 'divider'
          }}
        >
          <Tabs value={value} onChange={changeTab}>
            <Tab
              icon={<CalendarToday />}
              label='Reservation'
              sx={{ width: '100%' }}
            />
            <Tab icon={<MenuBook />} label='Order' sx={{ width: '100%' }} />
            <Tab icon={<DinnerDining />} label='Eat' sx={{ width: '100%' }} />
            <Tab icon={<TableRestaurant />} label='Table' sx={{ width: '100%' }} /> {/* should this be in the same page as Eat?? */}
            <Tab
              icon={<PointOfSale />}
              label='Payment'
              sx={{ width: '100%' }}
            />
          </Tabs>
        </Box>

        <Panel value={value} index={0}>
          <Reservation />
        </Panel>

        <Panel value={value} index={1}>
          <Order />
        </Panel>

        <Panel value={value} index={2}>
          <Eat />
        </Panel>

        <Panel value={value} index={3}>
          <Table />
        </Panel>

        <Panel value={value} index={4}>
          <Payment />
        </Panel>
      </Box>
    </CustomerContext.Provider>
  );
}

export default Customer;
