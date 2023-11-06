import React, { useState, useEffect } from 'react';

import {
  Box,
  Typography,
  Select,
  MenuItem,
  Button,
  TextField,
  Dialog,
  DialogTitle,
  DialogContent,
  DialogContentText,
  DialogActions
} from '@mui/material';

function Payment() {
  const [tip, setTip] = useState(0);
  const [total, setTotal] = useState(0);
  const [open, setOpen] = useState(false);
  const [socket, setSocket] = useState(null);
  const [paymentMethod, setPaymentMethod] = useState('card');

  useEffect(() => {
    const ws = new WebSocket('ws://tns303q8-8000.uks1.devtunnels.ms/ws');

    ws.onopen = () => {
      ws.send('C-Payment');
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

        if (type === 'make-order') {
          setTotal(data.totalPrice + Number(tip));
        }
      };
    }
  }, [socket]);

  const handlePayment = () => {
    if (socket) {
      socket.send(
        JSON.stringify({ type: 'make-payment', data: { total, paymentMethod } })
      );

      setOpen(true);
    }
  };

  const handleClose = () => {
    setOpen(false);
    window.close();
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
        Payment
      </Typography>

      <Box
        sx={{
          display: 'flex',
          alignItems: 'center',
          flexDirection: 'column',
          justifyContent: 'center'
        }}
      >
        <Typography variant='h3' sx={{ m: 2 }}>
          Total: R{total}
        </Typography>

        <TextField
          value={tip}
          label='Tip'
          type='number'
          variant='outlined'
          sx={{ m: 2, width: '100%' }}
          InputLabelProps={{ shrink: true }}
          onChange={(event) => {
            setTip(Number(event.target.value));
          }}
          onBlur={() => setTotal((prevTotal) => prevTotal + tip)}
        />

        <Select
          value={paymentMethod}
          sx={{ m: 2, width: '100%' }}
          onChange={(event) => setPaymentMethod(event.target.value)}
        >
          <MenuItem value={'card'}>Card</MenuItem>
          <MenuItem value={'cash'}>Cash</MenuItem>
          <MenuItem value={'split'}>Split</MenuItem>
        </Select>

        <Button
          size='large'
          sx={{ m: 2 }}
          variant='contained'
          onClick={handlePayment}
        >
          Pay
        </Button>
      </Box>

      <Dialog open={open} onClose={handleClose}>
        <DialogTitle>{'Payment Successful'}</DialogTitle>
        <DialogContent>
          <DialogContentText>Thank you for eating at KOS.</DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={handleClose}>Close</Button>
        </DialogActions>
      </Dialog>
    </Box>
  );
}

export default Payment;
