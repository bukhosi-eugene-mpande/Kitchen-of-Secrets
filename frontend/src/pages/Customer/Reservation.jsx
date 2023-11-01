import React, { useState, useEffect } from 'react';

import {
  Box,
  Button,
  Dialog,
  MenuItem,
  TextField,
  Typography,
  DialogTitle,
  DialogContent,
  DialogActions,
  DialogContentText
} from '@mui/material';

import LoadingButton from '@mui/lab/LoadingButton';

function Reservation({ socket }) {
  const [open, setOpen] = useState(false);
  const [loading, setLoading] = useState(false);

  const [name, setName] = useState('Ashley');
  const [seating, setSeating] = useState('Indoor');
  const [guests, setNumberOfGuests] = useState('1');

  const [time, setTime] = useState(
    new Date().toLocaleTimeString('en-US', {
      hour: 'numeric',
      minute: 'numeric',
      hour12: false
    })
  );

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const data = JSON.parse(event.data);
        if (data.available === 'yes') {
          setOpen(true);
          setLoading(false);
        }
      };
    }
  }, [socket]);

  function handleSubmit(e) {
    e.preventDefault();

    setLoading(true);

    const details = {
      name,
      time,
      guests,
      seating
    };

    if (socket) {
      socket.send(JSON.stringify({ type: 'make-res', ...details }));
    }
  }

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
          type='text'
          value={name}
          sx={{ m: 3 }}
          label='Name'
          onChange={(e) => setName(e.target.value)}
          helperText='Please enter your name'
        />

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
          onChange={(e) => setSeating(e.target.value)}
          helperText='Please select where you would like to eat'
        >
          <MenuItem value='Indoor'>Indoor</MenuItem>
          <MenuItem value='Outdoor'>Outdoor</MenuItem>
        </TextField>

        <TextField
          required
          fullWidth
          type='number'
          sx={{ m: 3 }}
          value={guests}
          label='Number of Guests'
          onChange={(e) => setNumberOfGuests(e.target.value)}
          helperText='Please enter the number of guests to reserve for'
        />

        <LoadingButton
          size='large'
          type='submit'
          color='primary'
          loading={loading}
          variant='contained'
        >
          Reserve
        </LoadingButton>
      </Box>

      <Dialog open={open} onClose={() => setOpen(false)}>
        <DialogTitle>Reservation Confirmation</DialogTitle>
        <DialogContent>
          <DialogContentText>
            Your reservation has been confirmed. Please arrive on time.
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={() => setOpen(false)}>OK</Button>
        </DialogActions>
      </Dialog>
    </Box>
  );
}

export default Reservation;
