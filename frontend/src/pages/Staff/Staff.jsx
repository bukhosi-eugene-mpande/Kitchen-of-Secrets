import React, { useRef, useState, useEffect } from 'react';

import { Box, Tab, Tabs } from '@mui/material';
import { CalendarToday, Restaurant, Payments } from '@mui/icons-material';

import Reservations from './Reservations';
import Panel from '../../components/Panel';

function Staff() {
  const socket = useRef(null);
  const [value, setValue] = useState(0);

  useEffect(() => {
    socket.current = new WebSocket('ws://localhost:8000/ws');

    socket.current.onopen = () => {
      socket.current.send('Staff');
    };

    return () => {
      if (socket.current) {
        socket.current.close(1000, 'Staff disconnected');
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
          <Tab icon={<Restaurant />} label='Order' sx={{ width: '100%' }} />
          <Tab icon={<Payments />} label='Payment' sx={{ width: '100%' }} />
        </Tabs>
      </Box>

      <Panel value={value} index={0}>
        <Reservations socket={socket.current} />
      </Panel>

      <Panel value={value} index={1}></Panel>

      <Panel value={value} index={2}></Panel>
    </Box>
  );
}

export default Staff;
