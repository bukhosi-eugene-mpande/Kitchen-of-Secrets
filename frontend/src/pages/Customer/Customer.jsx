import React, { useState, useEffect } from 'react';

import { Box, Tab, Tabs } from '@mui/material';
import { CalendarToday, Restaurant, Payments } from '@mui/icons-material';

import Order from './Order';
import Payment from './Payment';
import Reservation from './Reservation';
import Panel from '../../components/Panel';

function Customer() {
  console.log('Render Customer');

  const [value, setValue] = useState(0);
  const [socket, setSocket] = useState(null);

  useEffect(() => {
    const newSocket = new WebSocket('ws://localhost:8000/ws');

    setSocket(newSocket);

    newSocket.onopen = () => {
      newSocket.send('Customer');
    };

    return () => {
      newSocket.close(1000, 'Component unmounted');
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
          <Tab icon={<Restaurant />} label='Order' sx={{ width: '100%' }} />
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
        <Payment />
      </Panel>
    </Box>
  );
}

export default Customer;
