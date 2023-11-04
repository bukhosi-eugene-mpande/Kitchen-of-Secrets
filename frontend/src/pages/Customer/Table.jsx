import React from 'react';
import { useState } from 'react';
import { useSpring, animated } from 'react-spring';
import { Link } from 'react-router-dom';
import ghostImage from '../SVG/customer_1.svg'; 
import tableImage from '../SVG/table.svg';

const Table = () => {

    const handleSendOrder = () => {
    // fetch('https://api.example.com/send-order', {
    //   method: 'POST',
    //   headers: {
    //     'Content-Type': 'application/json',
    //   },
    //   body: JSON.stringify(yourOrderData),
    // })
    //   .then(response => response.json())
    //   .then(data => {
    //     console.log(data);
    //   })
    //   .catch(error => {
    //     console.log(error);
    //   });
    };

    const handlePayOrder = () => {   
    // fetch('https://api.example.com/pay-order', {
    //   method: 'POST',
    //   headers: {
    //     'Content-Type': 'application/json',
    //   },
    //   body: JSON.stringify(yourPaymentData),
    // })
    //   .then(response => response.json())
    //   .then(data => {
    //     console.log(data);
    //   })
    //   .catch(error => {
    //     console.log(error);
    //   });
    };

    const [sendOrderHovered, setSendOrderHovered] = useState(false);
    const [payOrderHovered, setPayOrderHovered] = useState(false);

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
                
                <div className='row justify-content-center col-12 mt-5'>
                <Link to="/order">
                    <button className="col-5 mt-5 button-64 mx-3" style={buttonStyle} onClick={handleSendOrder} onMouseEnter={() => setSendOrderHovered(true)}
                    onMouseLeave={() => setSendOrderHovered(false)}>
                        <span style={{
                        ...spanStyle,
                        background: sendOrderHovered ? 'none' : spanStyle.backgroundColor,
                        }}>Send Order</span>   
                    </button>
                </Link>
                <Link to="/payment">
                    <button className="col-5 mt-5 button-64 mx-3" style={buttonStyle} onClick={handlePayOrder} onMouseEnter={() => setPayOrderHovered(true)}
            onMouseLeave={() => setPayOrderHovered(false)}>
                        <span style={{
                        ...spanStyle,
                        background: payOrderHovered ? 'none' : spanStyle.backgroundColor,
                        }}>Pay Order</span>   
                    </button>
                </Link>
                </div> 
            </div>

            <div className="row " style={footerSec}>
                <div className="col-2 mt-1 mx-2 justify-content-center">
                    <p>some logo?</p>
                </div>
           
                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle}>
                    <a href="https://github.com/Gini24mp/Kitchen-of-Secrets">GitHub</a>
                </button>  

                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle}>
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

// const buttonStyle2 = {
//     // margin: '10px',
//     padding: '10px',
//     fontSize: '16px',
//     backgroundColor: '#',
// };

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

export default Table;
