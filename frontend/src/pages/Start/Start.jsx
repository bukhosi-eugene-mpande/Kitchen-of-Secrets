import React from 'react';
import { useNavigate } from 'react-router-dom';

import { Box, Button, Typography } from '@mui/material';

function Start() {
  const navigate = useNavigate();
  
  return (
    <Box
      sx={{
        display: 'flex',
        height: '100vh',
        alignItems: 'center',
        flexDirection: 'column',
        justifyContent: 'center'
      }}
    >
      <Typography variant='h1' sx={{ m: 2 }}>
        Welcome To The Kitchen Of Secrets
      </Typography>

      <Typography variant='h4' sx={{ m: 2 }}>
        Do you wanna be a Customer or Staff?
      </Typography>

      <Button
        size='large'
        sx={{ m: 2 }}
        variant='contained'
        onClick={() => navigate('/customer')}
      >
        Customer
      </Button>
      <Button
        size='large'
        sx={{ m: 2 }}
        variant='contained'
        onClick={() => navigate('/staff')}
      >
        Staff
      </Button>
    </Box>
  );
}

export default Start;
