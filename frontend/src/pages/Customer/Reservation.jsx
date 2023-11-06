import React, { useState } from 'react';

import { Box, Button, MenuItem, TextField, Typography } from '@mui/material';

function Reservation() {
  const [seating, setSeatingPreference] = useState('indoor');
  const [numberOfPeople, setNumberOfPeople] = useState('1');
  const [time, setTime] = useState(
    new Date().toLocaleTimeString('en-US', {
      hour: 'numeric',
      minute: 'numeric',
      hour12: false
    })
  );

  const handleSubmit = (e) => {
    e.preventDefault();

    console.log('Time:', time);
    console.log('Seating Preference:', seating);
    console.log('Number of People:', numberOfPeople);
  };

  return (
    <Box
      sx={{
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <Typography variant='h1' sx={{ m: 2 }}>
        Reservation
      </Typography>

      <Typography variant='h3' sx={{ m: 2 }}>
        Fill Out The Form To Make Reservation
      </Typography>

      <Box
        component='form'
        onSubmit={handleSubmit}
        sx={{
          m: 2,
          display: 'flex',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <TextField
          required
          fullWidth
          type='time'
          value={time}
          sx={{ m: 3 }}
          label='Desired Time'
          onChange={(e) => setTime(e.target.value)}
          helperText='Please enter the time you would like to eat'
        />

        <TextField
          select
          required
          fullWidth
          label='Area'
          sx={{ m: 3 }}
          value={seating}
          onChange={(e) => setSeatingPreference(e.target.value)}
          helperText='Please select where you would like to eat'
        >
          <MenuItem value='indoor'>Indoor</MenuItem>
          <MenuItem value='outdoor'>Outdoor</MenuItem>
        </TextField>

        <TextField
          required
          fullWidth
          type='number'
          sx={{ m: 3 }}
          value={numberOfPeople}
          label='Number of People'
          onChange={(e) => setNumberOfPeople(e.target.value)}
          helperText='Please enter the number of people to reserve for'
        />

        <Button size='large' type='submit' variant='contained' color='primary'>
          Reserve
        </Button>
      </Box>
    </Box>
  );
}

export default Reservation;
