import React, { useState, useEffect, createContext } from 'react';
import { Box, Tab, Tabs, CircularProgress } from '@mui/material';
import {
  MenuBook,
  PointOfSale,
  CalendarToday,
  RestaurantMenu
} from '@mui/icons-material';
import Orders from './Orders/Orders';
import Reservations from './Reservations/Reservations';
import Panel from '../../components/Panel';

export const StaffContext = createContext();

function Staff() {
  const [value, setValue] = useState(0);
  const [socket, setSocket] = useState(null);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('Staff');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'Staff disconnected');
      }
    };
  }, []);

  const changeTab = (event, newValue) => {
    setValue(newValue);
  };

  if (!socket) {
    return <CircularProgress />;
  }

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
          <Reservations socket={socket} />
        </Panel>

        <Panel value={value} index={1}>
          <Orders socket={socket} />
        </Panel>

        <Panel value={value} index={2}></Panel>
      </Box>
    </StaffContext.Provider>
  );
}

export default Staff;
