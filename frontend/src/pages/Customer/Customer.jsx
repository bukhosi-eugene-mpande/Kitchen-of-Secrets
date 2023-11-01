import React, { useRef, useState, useEffect } from 'react';

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
  const socket = useRef(null);
  const [value, setValue] = useState(0);

  useEffect(() => {
    socket.current = new WebSocket('ws://localhost:8000/ws');

    socket.current.onopen = () => {
      socket.current.send('Customer');
    };

    return () => {
      socket.current.close(1000, 'Component unmounted');
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
        <Reservation socket={socket.current} />
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
