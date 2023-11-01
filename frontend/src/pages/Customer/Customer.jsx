import React, { useState, useEffect } from 'react';

import { Box, Tab, Tabs } from '@mui/material';

import {
  Payments,
  MenuBook,
  Restaurant,
  CalendarToday
} from '@mui/icons-material';

import Eat from './Eat';
import Order from './Order';
import Payment from './Payment';
import Reservation from './Reservation';
import Panel from '../../components/Panel';

function Customer() {
  console.log('Render Customer');
  const [socket, setSocket] = useState(null);
  const [value, setValue] = useState(0);

  useEffect(() => {
    const newSocket = new WebSocket('ws://localhost:8000/ws');

    newSocket.onopen = () => {
      newSocket.send('Customer');
    };

    setSocket(newSocket);

    return () => {
      if (newSocket) {
        newSocket.close(1000, 'Component unmounted');
      }
    };
  }, []);

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
          <Tab icon={<MenuBook />} label='Order' sx={{ width: '100%' }} />
          <Tab icon={<Restaurant />} label='Eat' sx={{ width: '100%' }} />
          <Tab icon={<Payments />} label='Payment' sx={{ width: '100%' }} />
        </Tabs>
      </Box>

      <Panel value={value} index={0}>
        <Reservation socket={socket} />
      </Panel>

      <Panel value={value} index={1}>
        <Order />
      </Panel>

      <Panel value={value} index={2}>
        <Eat />
      </Panel>

      <Panel value={value} index={3}>
        <Payment />
      </Panel>
    </Box>
  );
}

export default Customer;