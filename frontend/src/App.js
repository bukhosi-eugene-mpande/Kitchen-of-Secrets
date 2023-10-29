import React from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';

import Start from './pages/Start/Start';
import Staff from './pages/Staff/Staff';
import Customer from './pages/Customer/Customer';
import NotFound from './pages/NotFound/NotFound';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path='/' element={<Start />} />
        <Route path='*' element={<NotFound />} />
        <Route index path='/staff' element={<Staff />} />
        <Route index path='/customer' element={<Customer />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
