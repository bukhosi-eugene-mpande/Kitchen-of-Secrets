import React from 'react';
import customerImage from '../SVG/customer_1.svg'; 
import tableImage from '../SVG/table.svg';

function Table() {

    const handleSendOrder = () => {
        // Create and send your JSON request for sending an order.
        // You can use the fetch API or a library like Axios for making HTTP requests.
        // Example:
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
        // Create and send your JSON request for paying an order.
        // Example:
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

    return (
        <div style={containerStyle}>
            <div className="row mt-5">
                <div className='col-3 '>
                    <img src={customerImage} alt="Customer" style={imageStyle} />
                </div>
                <div className='col-9 '>
                    <img src={tableImage} alt="Table" style={imageStyle2} />
                </div>
            {/* </div> */}
            {/* <div className="row "> */}
                <button className="col-5 mt-5 mx-2 justify-content-center" style={buttonStyle} onClick={handleSendOrder}>
                    Send Order
                </button>
           
                <button className="col-5 mt-5 justify-content-center" style={buttonStyle} onClick={handlePayOrder}>
                    Pay Order
                </button>
            </div>

            <div className="row " style={footerSec}>
                <div className="col-2 mt-1 mx-2 justify-content-center">
                    <p>some picture...</p>
                </div>
           
                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle}>
                    <a href="https://github.com/Gini24mp/Kitchen-of-Secrets">GitHub</a>
                </button>  

                <button className="col-2 mt-1 mx-2 justify-content-center" style={buttonStyle} onClick={handleSendOrder}>
                    Documentation 
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
};

const buttonStyle = {
    // margin: '10px',
    padding: '10px',
    fontSize: '16px',
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
