import React from 'react';
import { useState } from 'react';
import { Link } from 'react-router-dom';
import { useDrag } from 'react-use-gesture';
import { useSpring, animated } from 'react-spring';
import { interpolate } from 'react-spring';

import managerImage from '../assets/SVG/manager_1.svg'; 
import waiterImage from '../assets/SVG/waiter1_1.svg'; 
import waiterImage2 from '../assets/SVG/waiter2.svg'; 
import tableImage from '../assets/SVG/privTable.svg';
import pumpkinImage from '../assets/SVG/pumpkin_1.svg';
import headChefImage from '../assets/SVG/headChef.svg';

const PrivateRestaurant = () => {
    const handleDoRounds = () => {
      setHeadChefVisible(true);
        // Create and send your JSON request for doing rounds.
        // Example:
        // fetch('https://api.example.com/do-rounds', {
        //   method: 'POST',
        //   headers: {
        //     'Content-Type': 'application/json',
        //   },
        //   body: JSON.stringify(yourDoRoundsData),
        // })
        //   .then(response => response.json())
        //   .then(data => {
        //     console.log(data);
        //   })
        //   .catch(error => {
        //     console.log(error);
        //   });
    };

    const handleBuyIngredients = () => {
        // Create and send your JSON request for buying more ingredients.
        // Example:
        // fetch('https://api.example.com/buy-ingredients', {
        //   method: 'POST',
        //   headers: {
        //     'Content-Type': 'application/json',
        //   },
        //   body: JSON.stringify(yourBuyIngredientsData),
        // })
        //   .then(response => response.json())
        //   .then(data => {
        //     console.log(data);
        //   })
        //   .catch(error => {
        //     console.log(error);
        //   });
    };

    const handleSendWaiter = () => {
        // Create and send your JSON request for sending a waiter to a table.
        // Example:
        // fetch('https://api.example.com/send-waiter', {
        //   method: 'POST',
        //   headers: {
        //     'Content-Type': 'application/json',
        //   },
        //   body: JSON.stringify(yourSendWaiterData),
        // })
        //   .then(response => response.json())
        //   .then(data => {
        //     console.log(data);
        //   })
        //   .catch(error => {
        //     console.log(error);
        //   });
    };

    //animation for manager
    const [teetered, setTeetered] = useState(false);

    const teeterAnimation = {
      transformOrigin: 'center bottom', // Set the pivot point at the bottom center of the image
      transition: 'transform 1s ease-in-out', // Define the transition property for smooth animation
      transform: 'rotate(0deg)', // Initial position
    };
    
    if (teetered) {
      teeterAnimation.transform = 'rotate(8deg)'; // Final position when hovering
    }

    const [roundsHovered, setRoundsHovered] = useState(false);
    const [buyMoreHovered, setBuyMoreHovered] = useState(false);
    const [sendWaiterHovered, setSendWaiterHovered] = useState(false);
   
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

    const currBalance = () => {
      // this is where you call the current balance of the manager/player
    }
  
    //managing the animation of the headChef
    const [headChefVisible, setHeadChefVisible] = useState(false);
    const [headChefPosition, setHeadChefPosition] = useState({ x: -500, y: 50 });

    const chefAnimation = useSpring({
      to: async (next, cancel) => {
        // Chef appears and walks across the table
        await next({ x: 850 });
        // Chef walks back and disappears
        await next({ x: -100 });
        setHeadChefVisible(false); // Hide the chef when the animation is done
      },
      from: { x: -500 },
      config: { duration: 7000 }, 
      onRest: () => {
        // Animation has finished
      },
    });

  return (
      <div style={containerStyle}>
      {/* this is the waiter section */}
      <img
            src={waiterImage}
            alt="Waiter"
            style={{
                ...imageStyle3,
                transform: `translate3d(${waiterPosition.x}px, ${waiterPosition.y}px, 0)`,
            }}
            {...bindWaiter()}
        />
        <img
            src={waiterImage2}
            alt="Waiter"
            style={{
                ...imageStyle3,
                transform: `translate3d(${waiterPosition2.x}px, ${waiterPosition2.y}px, 0)`,
            }}
            {...bindWaiter2()}
        />
      <div className="container">
        <div className='row justify-content-center'><h3>Your Current Balance is: ${currBalance}</h3></div>
        <div className="row mt-5">
          <div className='col-3 '>
              <img src={managerImage} alt="Manager" style={{ ...imageStyle, ...teeterAnimation }}
                  onMouseEnter={() => setTeetered(true)}
                  onMouseLeave={() => setTeetered(false)} />
          </div>
          <div className='col-9'> 
            <div style={tableContainerStyle}>
            {/* this is the table section below */}
            <img className="col-3" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3 mt-5" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3 mt-5" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3 mt-5" src={tableImage} alt="Table" style={imageStyle2} />
            <img className="col-3 mt-5" src={tableImage} alt="Table" style={imageStyle2} />
            </div>
            {headChefVisible && (
              <div style={chefContainerStyle}>
                <animated.img
                  src={headChefImage}
                  alt="Head Chef"
                  style={{
                    ...imageStyle3,
                    transform: chefAnimation.x.interpolate(x => `translate3d(${x}px, ${headChefPosition.y}px, 0)`),
                  }}
                />
              </div>
            )}
          </div>
          <div className='row justify-content-center col-12 mt-5'>
              <button className="col-4 mt-5 mr-2 button-64 " onClick={handleDoRounds} style={buttonStyle} onMouseEnter={() => setRoundsHovered(true)} onMouseLeave={() => setRoundsHovered(false)}>
                <span style={{
                    ...spanStyle,
                    background: roundsHovered ? 'none' : spanStyle.backgroundColor,
                    }}>Do Rounds</span>
              </button>
              <button className="col-4 mt-5 mr-2 button-64 " style={buttonStyle} onMouseEnter={() => setBuyMoreHovered(true)} onMouseLeave={() => setBuyMoreHovered(false)} onClick={handleBuyIngredients}>
                <span style={{
                    ...spanStyle,
                    background: buyMoreHovered ? 'none' : spanStyle.backgroundColor,
                    }}>Buy More Ingredients</span>
              </button>
              <button className="col-4 mt-3 button-64 " style={buttonStyle} onMouseEnter={() => setSendWaiterHovered(true)} onMouseLeave={() => setSendWaiterHovered(false)} onClick={handleSendWaiter}>
                <span style={{
                    ...spanStyle,
                    background: sendWaiterHovered ? 'none' : spanStyle.backgroundColor,
                    }}>Send Waiter to Table</span>
              </button>
          </div>
        </div>
      </div>
      <div className="row mt-5" style={footerSec}>
          <div className="col-2 mt-4 mx-2 justify-content-center">
              <p>some logo? </p>
          </div>
    
          <button className="col-2 mt-4 mx-2 justify-content-center" style={buttonStyle2}>
              <a href="https://github.com/Gini24mp/Kitchen-of-Secrets">GitHub</a>
          </button>  

          <button className="col-2 mt-4 mx-2 justify-content-center" style={buttonStyle2}>
              <a href="">Documentation</a>
              {/* this would be a link to doxygen */}
          </button> 
      </div>                
      
    </div>
  );

}


const containerStyle = {
  display: 'flex',
  flexDirection: 'row',
  alignItems: 'center',
  justifyContent: 'center',
  height: '100vh',
  width: '100vw',
  padding: '10px',
  fontFamily: 'Roboto',
};

const imageStyle = {
  width: '150px', 
};

const imageStyle2 = {
  width: '600px', 
  marginleft: '50%',
};

const imageStyle3 = {
    width: '90px', 
    marginleft: '40%',
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
  cursor: 'pointer',
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
  cursor: 'pointer',
}

const spanStyle = {
  backgroundColor: 'rgb(5, 6, 45)',
  padding: '16px 24px',
  borderRadius: '6px',
  width: '100%',
  height: '100%',
  transition: 'background 300ms', 
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
  color: 'white',
}

const tableContainerStyle = {
  position: 'relative', // Required to maintain relative positioning of tableImage elements
};

const chefContainerStyle = {
  position: 'absolute', // Positioned absolutely to appear in front
  top: 0,
  left: 0,
  zIndex: 1, // Higher z-index to appear in front of tableImage elements
};

export default PrivateRestaurant;
