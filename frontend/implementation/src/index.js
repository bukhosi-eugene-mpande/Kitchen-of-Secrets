import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import { BrowserRouter as Router, Routes, Route, Link } from 'react-router-dom';
import './index.css';

function App() {
	return (
	  <Router>
		<div className="App">
		  <nav className="row navbar navbar-expand-lg navbar-light bg-light">
			<Link to="/" className="col-2 mt-2 offset-1">Home</Link>
			<Link to="/our-team" className="col-2 mt-3 offset-5">Our Team</Link>
		  </nav>
  
		  <header className="App-header">
			<h1>Welcome to Our Kitchen of Secrets</h1>
			<div className="btn-group">
			  <Link to="/page1">
				<button className="btn btn-primary">Customer</button>
			  </Link>
			  <Link to="/page2">
				<button className="btn btn-primary">Manager</button>
			  </Link>
			</div>
		  </header>
  
		  <Routes>
			<Route path="/our-team" element={<OurTeam />} />
			<Route path="/page1" element={<Page1 />} />
			<Route path="/page2" element={<Page2 />} />
		  </Routes>a
		</div>
	  </Router>
	);
  }
function OurTeam() {
  return <div>Our Team Page</div>;
}

function Page1() {
  const [tableStatus, setTableStatus] = useState(Array(6).fill(false));
  const [clickedCustomers, setClickedCustomers] = useState(Array(6).fill(false));

  const handleCustomerClick = (index) => {
    const updatedTableStatus = [...tableStatus];
    const updatedClickedCustomers = [...clickedCustomers];

    updatedTableStatus[index] = true;
    updatedClickedCustomers[index] = true;

    setTableStatus(updatedTableStatus);
    setClickedCustomers(updatedClickedCustomers);
  }

  
	const customerImages = Array.from({ length: 6 }, (_, index) => (
		<div key={`customer-${index}`} className="col-2" onClick={() => handleCustomerClick(index)}>
		  <img src={`/customers/customer${index}.png`} alt={`Customer ${index}`} />
		</div>
	  ));
	  const tableImages = Array.from({ length: 6 }, (_, tableIndex) => {
		const tableStatusIndex = tableStatus[tableIndex] === undefined ? false : tableStatus[tableIndex];
		const src = tableStatusIndex ? `/tables/BookedTable${tableIndex}.png` : `/tables/table${tableIndex}.png`;
		return (
		  <div key={`table-${tableIndex}`} className="col-2">
			<img src={src} alt={`Table ${tableIndex}`} />
		  </div>
		);
	  });
  
  
	return (
	  <div className="page1">
		<div className="page1-background">
		  <h1>Reservation</h1>
		  <div className="row customers">{Array.from({ length: 6 }, (_, index) => (
            <div key={`customer-${index}`} className="col-2" onClick={() => handleCustomerClick(index)}>
              {clickedCustomers[index] ? null : (
                <img src={`/customers/customer${index}.png`} alt={`Customer ${index}`} />
              )}
            </div>
          ))}
		  </div>
		  <hr />
		  <div className="row tables">{tableImages}</div>
		</div>
	  </div>
	);
  }

function Page2() {
  return <div>Page 2 Content</div>;
}
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<App />);