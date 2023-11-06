import React from 'react';
import { useState } from 'react';
import { useSpring, animated } from 'react-spring';
import ghostImage from '../assets/SVG/customer_1.svg'; 
import tableImage from '../assets/SVG/table.svg';
import Logo from '../assets/png/logo.png';

const Table = () => {
    
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

    return (
        <div style={containerStyle}>
            <div className="row mt-5">
                <div className='col-3 '>
                    {/* <img src={customerImage} alt="Customer" style={imageStyle} /> */}
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
                <div className='col-9 '>
                    <img src={tableImage} alt="Table" style={imageStyle2} />
                </div>
                
            </div>

            <div className="row " style={footerSec}>
                <div className="col-2 mt-1 mx-2 justify-content-center">
                    <img src={Logo} width="100px" alt="logo"/>
                </div>
           
                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle2}>
                    <a href="https://github.com/Gini24mp/Kitchen-of-Secrets">GitHub</a>
                </button>  

                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle2}>
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
    // height: '100vh',
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

export default Table;
