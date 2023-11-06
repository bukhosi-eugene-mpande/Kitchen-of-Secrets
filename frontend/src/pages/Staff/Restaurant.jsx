import React from 'react';
import { useState } from 'react';
import { useDrag } from 'react-use-gesture';
import { useSpring, animated } from 'react-spring';
import { interpolate } from 'react-spring';

import managerImage from '../assets/SVG/manager_1.svg';
import waiterImage from '../assets/SVG/waiter1_1.svg';
import waiterImage2 from '../assets/SVG/waiter2.svg';
import tableImage from '../assets/SVG/table.svg';
import headChefImage from '../assets/SVG/headChef.svg';

const Restaurant = () => {
  const handleDoRounds = () => {
    // Set head chef to be visible
    setHeadChefVisible(true);
  };

  //animation for manager
  const [teetered, setTeetered] = useState(false);

  const teeterAnimation = {
    transformOrigin: 'center bottom', // Set the pivot point at the bottom center of the image
    transition: 'transform 1s ease-in-out', // Define the transition property for smooth animation
    transform: 'rotate(0deg)' // Initial position
  };

  if (teetered) {
    teeterAnimation.transform = 'rotate(8deg)'; // Final position when hovering
  }

  const [roundsHovered, setRoundsHovered] = useState(false);

  // Initial positions for waiters
  const [waiterPosition, setWaiterPosition] = useState({ x: 100, y: 150 });
  const [waiterPosition2, setWaiterPosition2] = useState({ x: 100, y: 200 });

  // this is the drag function for the waiter within table section...which is not specific to the tables.
  const bindWaiter = useDrag(({ offset: [x, y] }) => {
    setWaiterPosition({ x, y });
  });

  const bindWaiter2 = useDrag(({ offset: [x, y] }) => {
    setWaiterPosition2({ x, y });
  });

  //managing the animation of the headChef
  const [headChefVisible, setHeadChefVisible] = useState(false);
  const [headChefPosition, setHeadChefPosition] = useState({ x: -200, y: 0 });

  const chefAnimation = useSpring({
    to: async (next, cancel) => {
      // Chef appears and walks across the table
      await next({ x: 850 });
      // Chef walks back and disappears
      await next({ x: -100 });
      setHeadChefVisible(false); // Hide the chef when the animation is done
    },
    from: { x: -200 },
    config: { duration: 7000 },
    onRest: () => {
      // Animation has finished
    }
  });
  return (
    <div style={containerStyle}>
      {/* this is the waiter section */}
      <img
        src={waiterImage}
        alt='Waiter'
        style={{
          ...imageStyle3,
          transform: `translate3d(${waiterPosition.x}px, ${waiterPosition.y}px, 0)`
        }}
        {...bindWaiter()}
      />
      <img
        src={waiterImage2}
        alt='Waiter'
        style={{
          ...imageStyle3,
          transform: `translate3d(${waiterPosition2.x}px, ${waiterPosition2.y}px, 0)`
        }}
        {...bindWaiter2()}
      />
      <div className='container'>
        {/* <div className='row justify-content-center'><h3>Your Current Balance is: ${currBalance}</h3></div> */}
        <div className='row '>
          <div className='col-3 '>
            <img
              src={managerImage}
              alt='Manager'
              style={{ ...imageStyle, ...teeterAnimation }}
              onMouseEnter={() => setTeetered(true)}
              onMouseLeave={() => setTeetered(false)}
            />
          </div>
          <div className='col-9'>
            {/* this is the table section below */}
            <div style={tableContainerStyle}>
              <img
                className='col-3'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3 mt-5'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3 mt-5'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3 mt-5'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
              <img
                className='col-3 mt-5'
                src={tableImage}
                alt='Table'
                style={imageStyle2}
              />
            </div>
            {headChefVisible && (
              <div style={chefContainerStyle}>
                <animated.img
                  src={headChefImage}
                  alt='Head Chef'
                  style={{
                    ...imageStyle3,
                    transform: chefAnimation.x.interpolate(
                      (x) => `translate3d(${x}px, ${headChefPosition.y}px, 0)`
                    )
                  }}
                />
              </div>
            )}
          </div>
          <div className='row justify-content-center col-12 mt-5'>
            <button
              className='col-4 mt-5 button-64 '
              onClick={handleDoRounds}
              style={buttonStyle}
              onMouseEnter={() => setRoundsHovered(true)}
              onMouseLeave={() => setRoundsHovered(false)}
            >
              <span
                style={{
                  ...spanStyle,
                  background: roundsHovered ? 'none' : spanStyle.backgroundColor
                }}
              >
                Do Rounds
              </span>
            </button>
          </div>
        </div>
      </div>
    </div>
  );
};

const containerStyle = {
  display: 'flex',
  flexDirection: 'row',
  alignItems: 'center',
  justifyContent: 'center',
  height: '100vh',
  width: '100vw',
  padding: '10px',
  fontFamily: 'Roboto'
  // // position: 'relative', // Add this line
  // backgroundImage: `url(${Floor})`,
  // backgroundRepeat: 'no-repeat',
  // backgroundSize: 'cover',
};

const imageStyle = {
  width: '150px'
};

const imageStyle2 = {
  width: '600px',
  marginleft: '50%'
};

const imageStyle3 = {
  width: '90px',
  marginleft: '40%'
};

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
  cursor: 'pointer'
};

const buttonStyle2 = {
  alignItems: 'center',
  backgroundImage: 'black',
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
  cursor: 'pointer'
};

const spanStyle = {
  backgroundColor: 'rgb(5, 6, 45)',
  padding: '16px 24px',
  borderRadius: '6px',
  width: '100%',
  height: '100%',
  transition: 'background 300ms'
};

const footerSec = {
  position: 'absolute',
  bottom: '0',
  width: '100%',
  height: '60px',
  // backgroundColor: '#f5f5f5',
  textAlign: 'center',
  display: 'flex',
  flexDirection: 'row',
  alignItems: 'center',
  justifyContent: 'center',
  fontSize: '12px',
  color: 'white'
};

const tableContainerStyle = {
  position: 'relative' // Required to maintain relative positioning of tableImage elements
};

const chefContainerStyle = {
  position: 'absolute', // Positioned absolutely to appear in front
  top: 0,
  left: 0,
  zIndex: 1 // Higher z-index to appear in front of tableImage elements
};

export default Restaurant;
