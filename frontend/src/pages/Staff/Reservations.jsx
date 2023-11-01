import React, { useState, useEffect } from 'react';

import {
  Box,
  Button,
  List,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function Reservations({ socket }) {
  const [reservations, setReservations] = useState([]);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const newReservation = JSON.parse(event.data);
        setReservations((prevReservations) => [
          ...prevReservations,
          newReservation
        ]);
      };
    }
  }, [socket]);

  function handleAccept(name) {
    setReservations((prevReservations) =>
      prevReservations.map((reservation) =>
        reservation.name === name
          ? { ...reservation, accepted: true }
          : reservation
      )
    );

    if (socket) {
      socket.send(JSON.stringify({ type: 'accept-res', available: 'yes' }));
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
        Reservations
      </Typography>

      <List sx={{ p: 2 }}>
        {reservations.map((reservation, index) => (
          <ListItem
            key={index}
            sx={{
              m: 2,
              borderRadius: 2,
              border: '2px solid',
              borderColor: reservation.accepted ? 'grey' : 'primary.main'
            }}
          >
            <ListItemText
              primary={`${reservation.name} - ${reservation.seating} at ${reservation.time} for ${reservation.guests} guests`}
              secondary={reservation.accepted ? 'Accepted' : 'Pending'}
            />

            <Button
              variant='contained'
              disabled={reservation.accepted}
              onClick={() => handleAccept(reservation.name)}
            >
              {reservation.accepted ? 'Accepted' : 'Accept'}
            </Button>
          </ListItem>
        ))}
      </List>
    </Box>
  );
}

export default Reservations;
