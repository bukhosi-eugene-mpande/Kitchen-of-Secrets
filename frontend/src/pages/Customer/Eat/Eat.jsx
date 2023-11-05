import React, { useState, useEffect } from 'react';

import {
  Box,
  CircularProgress,
  LinearProgress,
  Button,
  Typography
} from '@mui/material';

function Eat() {
  const [socket, setSocket] = useState(null);
  const [progress, setProgress] = useState(0);
  const [foodStatus, setFoodStatus] = useState('waiting');

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('C-Eat');
    };

    setSocket(ws);

    return () => {
      if (ws) {
        ws.close(1000, 'C-Eat left');
      }
    };
  }, []);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const { type } = JSON.parse(event.data);

        if (type === 'serve-order') {
          setProgress(0);
          setFoodStatus('eating');

          const timer = setInterval(() => {
            setProgress((oldProgress) => {
              if (oldProgress === 100) {
                setFoodStatus('done');
                clearInterval(timer);
                return 100;
              }

              return Math.min(oldProgress + 1, 100);
            });
          }, 600);
        }
      };
    }
  }, [socket]);

  return (
    <Box
      sx={{
        height: '100vh',
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      {foodStatus === 'waiting' && (
        <>
          <CircularProgress
            sx={{ m: 2, width: '100px !important', height: '100px !important' }}
          />

          <Typography variant='h3'>Your food is being prepared...</Typography>

          <Button variant='contained' size='large'>
            Cancel Order
          </Button>
        </>
      )}

      {foodStatus === 'eating' && (
        <>
          <Typography variant='h3'>Eating...</Typography>

          <LinearProgress
            variant='determinate'
            value={progress}
            sx={{ m: 2, height: 10, width: '60%' }}
          />

          <Button variant='contained' size='large'>
            Enquire
          </Button>
        </>
      )}

      {foodStatus === 'done' && (
        <>
          <Typography variant='h2'>You finished eating.</Typography>

          <Button variant='contained' size='large' sx={{ m: 2 }}>
            Proceed To Payment
          </Button>
        </>
      )}
    </Box>
  );
}

export default Eat;
