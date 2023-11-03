import React from 'react';
import customerImage from '../SVG/customer.svg'; 
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

    return //(
        // <div style={containerStyle}>
        // <img src={customerImage} alt="Customer" style={imageStyle} />
        // <img src={tableImage} alt="Table" style={imageStyle} />
        // <button style={buttonStyle} onClick={handleSendOrder}>
        // Send Order
        // </button>
        // <button style={buttonStyle} onClick={handlePayOrder}>
        // Pay Order
        // </button>
        // </div>
    //);
}

const containerStyle = {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
    justifyContent: 'center',
    height: '100vh',
};

const imageStyle = {
    width: '200px', // should be 100% of container width
};

const buttonStyle = {
    margin: '10px',
    padding: '10px',
    fontSize: '16px',
};

export default Table;
