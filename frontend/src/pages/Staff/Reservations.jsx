import React, { useState, useEffect } from 'react';
import {
  Box,
  Button,
  List,
  ListItem,
  Typography,
  ListItemText
} from '@mui/material';

function Reservations() {
  const [reservations, setReservations] = useState([]);
  const [socket, setSocket] = useState(null);

  useEffect(() => {
    const newSocket = new WebSocket('ws://localhost:8000/ws');
    setSocket(newSocket);

    return () => {
      newSocket.close(1000, 'Staff disconnected');
    };
  }, []);

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

  const handleAccept = (name) => {
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