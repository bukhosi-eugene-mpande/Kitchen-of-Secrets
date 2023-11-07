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
  const [socket, setSocket] = useState(null);
  const [reservations, setReservations] = useState([]);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('S-Reservations');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'S-Reservations disconnected');
      }
    };
  }, []);

  useEffect(() => {
    if (socket) {
      socket.onmessage = addReservation;

      return () => {
        socket.onmessage = null;
      };
    }
  }, [socket]);

  const addReservation = (event) => {
    const { type, data } = JSON.parse(event.data);

    if (type === 'make-res') {
      setReservations((prevReservations) => [...prevReservations, data]);
    }
  };

  function handleAccept(name) {
    setReservations((prevReservations) =>
      prevReservations.map((reservation) =>
        reservation.name === name
          ? { ...reservation, accepted: true }
          : reservation
      )
    );

    if (socket) {
      socket.send(
        JSON.stringify({ type: 'accept-res', data: { available: 'yes' } })
      );
    }

    handleCustomerClick();
  }
  const [tableStatus, setTableStatus] = useState(Array(6).fill(false));

  const tableImages = Array.from({ length: 6 }, (_, tableIndex) => {
    const tableStatusIndex =
      tableStatus[tableIndex] === undefined ? false : tableStatus[tableIndex];
    const src = tableStatusIndex
      ? `/assets/tables/BookedTable${tableIndex}.png`
      : `/assets/tables/table${tableIndex}.png`;
    return (
      <div key={`table-${tableIndex}`} className='col-2'>
        <img style={{ width: '100px' }} src={src} alt={`Table ${tableIndex}`} />
      </div>
    );
  });

  const handleCustomerClick = () => {
    const updatedTableStatus = [...tableStatus];

    updatedTableStatus[0] = true;

    setTableStatus(updatedTableStatus);
  };

  return (
    <Box
      sx={{
        backgroundImage: `url('./assets/ReservationBackground.png')`,
        backgroundSize: 'cover',
        backgroundPosition: 'center',
        backgroundRepeat: 'no-repeat',
        minHeight: '100vh',
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <img
        src='./assets/dracula.png'
        alt='dracula'
        style={{
          position: 'absolute',
          bottom: '100px',
          left: '100px',
          transform: 'translateX(-50%)',
          width: '200px',
          height: 'auto',
          animation: 'moveLeftRight 4s linear infinite'
        }}
      />
      <Typography
        variant='h1'
        sx={{
          m: 2,
          color: 'white',
          fontFamily: 'Gloria Hallelujah, cursive',
          fontWeight: 700
        }}
      >
        Reservations
      </Typography>

      <List
        sx={{
          p:2,
          borderRadius: 2,
          backgroundColor: 'rgba(0, 0, 0, 0.7)'
        }}
      >
        {reservations.map((reservation, index) => (
          <ListItem
            key={index}
            sx={{
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

      <div>
        <h1>Available tables</h1>
        <div className='row tables'>{tableImages}</div>
      </div>
      <style>
        {`
          @keyframes moveLeftRight {
            0% {
              transform: translateX(-50%); // Start in the middle
            }
            50% {
              transform: translateX(50%); // Move to the right
            }
            100% {
              transform: translateX(-50%); // Move back to the middle
            }
          }
        `}
      </style>
    </Box>
  );
}

export default Reservations;
