import React, { useState, useEffect } from 'react';
import { useSpring, animated } from 'react-spring';
import ghostImage from '../../assets/SVG/customer_1.svg'; 
import tableOrange from '../../assets/png/tableorange.png';
import tableRed from '../../assets/png/tablered.png';
import tableNormal from '../../assets/SVG/table.svg';

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
  const [buttonClicks, setButtonClicks] = useState(0);
  const [tableImage, setTableImage] = useState(`${tableNormal}`);
  const [waitHovered, setWaitHovered] = useState(false);

  const handleWait = () => {
    if (buttonClicks < 2) {
      setButtonClicks(buttonClicks + 1);
      if (buttonClicks === 1) {
        setTableImage(`${tableRed}`);
      } else if (buttonClicks === 0) {
        setTableImage(`${tableOrange}`);
      }
    }
  };

  //floating for ghost animation
  const floatAnimation = useSpring({
    from: {
        transform: 'translate(0, 0)',
        opacity: 1,
    },
    to: async (next) => {
        while (true) {
        await next({
            transform: 'translate(0, -50px)',
            opacity: 0.7,
        });
        await next({
            transform: 'translate(0, 50px)',
            opacity: 1,
        });
        }
    },
    config: { duration: 2000 }, 
  });

  useEffect(() => {
    const ws = new WebSocket('ws://tns303q8-8000.uks1.devtunnels.ms/ws');

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
    <div className="row justify-content-center mt-3 mb-5">
        <div className='col-3 '>
            <animated.img 
            src={ghostImage}
            alt="Customer"
            style={{
            ...floatAnimation,
            position: 'absolute',
            top: '100px', 
            left: '0px',
            width: '150px', 
            height: 'auto', 
            zindex: '999',
            }}
        />
        </div>
        <div className='col-9'>
            <img src={tableImage} alt="Table" style={imageStyle2} />
        </div>
    </div>

    {/* <div className=""> */}
      {foodStatus === 'waiting' && (
        <>
          <CircularProgress
            sx={{ m: 2, width: '100px !important', height: '100px !important' }}
          />

          <Typography variant='h5'>Your food is being prepared...</Typography>

          {/* <Button variant='contained' size='large'>
            Cancel Order
          </Button> */}
        </>
      )}

      {foodStatus === 'eating' && (
        <>
          <Typography variant='h5'>Eating...</Typography>

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
          <Typography variant='h5'>You finished eating.</Typography>

          <Button variant='contained' size='large' sx={{ m: 2 }}>
            Proceed To Payment
          </Button>
        </>
      )}
    {/* </div> */}
    <div className='row justify-content-center col-12 mt-5'>
        {buttonClicks < 2 && (
          <button className="col-4 mt-5 button-64" onClick={handleWait} style={buttonStyle} onMouseEnter={() => setWaitHovered(true)} onMouseLeave={() => setWaitHovered(false)}>
            <span style={{
              ...spanStyle,
              background: waitHovered ? 'none' : spanStyle.backgroundColor,
            }}>Get Angry</span>
          </button>
        )}

        {/* {buttonClicks >= 2 && (
          <Typography variant='h5'>Button disabled</Typography>
        )} */}
      </div>
    </Box>

  );
}

const buttonStyle = {
  alignItems: 'center',
  backgroundImage: 'linear-gradient(144deg, #AF40FF, #5B42F3 50%, #00DDEB)',
  border: '0',
  borderRadius: '8px',
  boxShadow: 'rgba(151, 65, 252, 0.2) 0 15px 30px -5px',
  boxSizing: 'border-box',
  color: '#FFFFFF',
  display: 'flex',
  fontFamily: 'Phantomsans, sans-serif',
  fontSize: '20px',
  justifyContent: 'center',
  lineHeight: '1em',
  maxWidth: '100%',
  minWidth: '140px',
  padding: '3px',
  textDecoration: 'none',
  userSelect: 'none',
  WebkitUserSelect: 'none',
  touchAction: 'manipulation',
  whiteSpace: 'nowrap',
  cursor: 'pointer',
};

const spanStyle = {
  backgroundColor: 'rgb(5, 6, 45)',
  padding: '16px 24px',
  borderRadius: '6px',
  width: '100%',
  height: '100%',
  transition: 'background 300ms', 
};

const imageStyle2 = {
  width: '600px', 
  marginleft: '50%',
  zindex: '-1',
};

export default Eat;