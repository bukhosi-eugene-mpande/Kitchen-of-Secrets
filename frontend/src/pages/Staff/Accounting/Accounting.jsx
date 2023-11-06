import React, { useState, useEffect } from 'react';

import {
  Box,
  Button,
  Dialog,
  Typography,
  DialogTitle,
  DialogContent,
  DialogActions,
  DialogContentText
} from '@mui/material';

function Accounting() {
  const [open, setOpen] = useState(false);
  const [socket, setSocket] = useState(null);
  const [bankBalance, setBankBalance] = useState(0);
  const [paymentAmount, setPaymentAmount] = useState(0);

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000/ws');

    ws.onopen = () => {
      ws.send('S-Accounting');
    };

    setSocket(ws);

    return () => {
      ws.close();
    };
  }, []);

  useEffect(() => {
    if (socket) {
      socket.onmessage = (event) => {
        const { type, data } = JSON.parse(event.data);

        if (type === 'make-payment') {
          setOpen(true);
          setPaymentAmount(data.total);
          setBankBalance((prevBalance) => prevBalance + data.total);
        }
      };
    }
  }, [socket]);

  const handleClose = () => {
    setOpen(false);
  };

  return (
    <Box
      sx={{
        backgroundImage: `url('./assets/PaymentBackground.png')`,
        backgroundSize: 'cover',
        backgroundPosition: 'top',
        backgroundRepeat: 'no-repeat',
        minHeight: '100vh',
        display: 'flex',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <img
        src="./assets/customers/customer0.png"
        alt="skeleton"
        style={{
          position: 'absolute',
          bottom: '100px',
          left: '100px',
          width: '200px',
          height: 'auto',
        }}
      />
      <img
        src="./assets/customers/customer0.png"
        alt="skeleton"
        style={{
          position: 'absolute',
          bottom: '100px',
          right: '100px',
          width: '200px',
          height: 'auto',
        }}
      />
      <Typography variant='h1' sx={{ m: 2,color: 'white',
        fontFamily: 'Gloria Hallelujah, cursive',
        fontWeight: 700 }}>
        Accounting
      </Typography>

      <Typography variant='h2' sx={{ m: 2 ,
        backgroundColor: 'rgba(0, 0, 0, 0.7)',
        padding: '20px',
        borderRadius: '10px' }}>
        Bank Balance: R{bankBalance}
      </Typography>

      <Dialog open={open} onClose={handleClose}>
        <DialogTitle>{'Payment Received'}</DialogTitle>
        <DialogContent>
          <DialogContentText>
            A payment of R{paymentAmount} has been received.
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={handleClose}>Close</Button>
        </DialogActions>
      </Dialog>
    </Box>
  );
}

export default Accounting;
