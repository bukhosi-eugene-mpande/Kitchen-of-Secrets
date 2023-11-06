import React from 'react';
import { useNavigate } from 'react-router-dom';

import { Box, Button, Typography } from '@mui/material';

function Start() {
  const navigate = useNavigate();

  const appStyle = {
    backgroundImage: `url('./assets/HomePageBack.png')`,
    backgroundSize: 'cover',
    backgroundPosition: 'center',
    backgroundRepeat: 'no-repeat',
    minHeight: '100vh',
    alignItems: 'center',
    display: 'flex',
    flexDirection: 'column',
    justifyContent: 'center',
    position: 'relative'
  };

  const headerStyle = {
    textAlign: 'center',
  };

  const h1Style = {
    color: 'white',
    fontFamily: 'Gloria Hallelujah, cursive',
    fontWeight: 700,
  };
  const footerStyle = {
    backgroundColor: 'purple',
    color: 'white',
    padding: '10px',
    textAlign: 'center',
    position: 'absolute',
    bottom: 0,
    width: '100%',
  };

  const linkStyle = {
    color: 'white',
    textDecoration: 'none',
    margin: '10px',
  };


  return (
    <Box
      sx={appStyle}
    >
       

       <div className="App-header" style={headerStyle}>
        <h1 style={h1Style}>Welcome To The Kitchen Of Secrets</h1>
      </div>

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

      <footer style={footerStyle}>
        <a href="https://github.com" style={linkStyle}>
          GitHub
        </a>
        <a href="https://documentation-link.com" style={linkStyle}>
          Documentation
        </a>
        <a href="/our-team" style={linkStyle}>
          Our Team
        </a>
      </footer>
    </Box>
  );
}

export default Start;
