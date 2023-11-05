import React, { useState, useEffect } from 'react';

import {
  Box,
  Typography,
  Select,
  MenuItem,
  Button,
  TextField
} from '@mui/material';

function Payment() {
  const [tip, setTip] = useState(0);
  const [total, setTotal] = useState(0);
  const [socket, setSocket] = useState(null);
  const [paymentMethod, setPaymentMethod] = useState('card');

  useEffect(() => {
    const ws = new WebSocket('ws://localhost:8000');

    ws.onmessage = (event) => {
      const { type, data } = JSON.parse(event.data);

      if (type === 'make-order') {
        setTotal(data.total + Number(tip));
      }
    };

    setSocket(ws);

    return () => {
      ws.close();
    };
  }, [tip]);

  const handlePayment = () => {
    if (socket) {
      socket.send(JSON.stringify({ total, paymentMethod }));
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
          sx={{ m: 2, width: '100%' }}
          variant='outlined'
          InputLabelProps={{ shrink: true }}
          onChange={(event) => {
            setTip(Number(event.target.value));
          }}
          onBlur={() => setTotal((prevTotal) => prevTotal + tip)}
        />

        <Select
          sx={{ m: 2, width: '100%' }}
          value={paymentMethod}
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
    </Box>
  );
}

export default Payment;
