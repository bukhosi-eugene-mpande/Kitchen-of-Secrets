import React, { useState, createContext } from 'react';

import { Box, Tab, Tabs } from '@mui/material';

import {
  MenuBook,
  PointOfSale,
  CalendarToday,
  RestaurantMenu
} from '@mui/icons-material';

import Cook from './Cook/Cook';
import Orders from './Orders/Orders';
import Panel from '../../components/Panel';
import Accounting from './Accounting/Accounting';
import Reservations from './Reservations/Reservations';

export const StaffContext = createContext();

function Staff() {
  const [value, setValue] = useState(0);

  const changeTab = (event, newValue) => {
    setValue(newValue);
  };

  return (
    <StaffContext.Provider value={{ changeTab }}>
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
              label='Reservations'
              sx={{ width: '100%' }}
            />
            <Tab icon={<MenuBook />} label='Orders' sx={{ width: '100%' }} />
            <Tab
              icon={<RestaurantMenu />}
              label='Cook'
              sx={{ width: '100%' }}
            />
            <Tab
              icon={<PointOfSale />}
              label='Accounting'
              sx={{ width: '100%' }}
            />
          </Tabs>
        </Box>

        <Panel value={value} index={0}>
          <Reservations />
        </Panel>

        <Panel value={value} index={1}>
          <Orders />
        </Panel>

        <Panel value={value} index={2}>
          <Cook />
        </Panel>

        <Panel value={value} index={3}>
          <Accounting />
        </Panel>
      </Box>
    </StaffContext.Provider>
  );
}

export default Staff;
