import React from 'react';
import { useNavigate } from 'react-router-dom';

import { Box, Button, Typography, Link } from '@mui/material';

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
    backgroundColor: 'primary.main',
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
       
       <img
  src="./assets/flyingBat.gif"
  alt="Flying Bat"
  style={{
    position: 'absolute',
    top: '100px',
    right: '100px', 
    width: '200px',
    height: 'auto'
  }}
/>
<img
  src="./assets/flyingBat.gif"
  alt="Flying Bat"
  style={{
    position: 'absolute',
    bottom: '100px', 
    left: '100px',
    width: '200px', 
    height: 'auto'
  }}
/>
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

      <Box variant='footer' sx={footerStyle}>
        <Link href="https://github.com" sx={linkStyle}>
          GitHub
        </Link>
        <Link href="https://documentation-link.com" sx={linkStyle}>
          Documentation
        </Link>
        <Link href="/our-team" sx={linkStyle}>
          Our Team
        </Link>
      </Box>
    </Box>
  );
}

export default Start;
