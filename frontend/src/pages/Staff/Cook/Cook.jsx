import React, { useEffect, useState } from 'react';

function Cook({ socket }) {
  const [order, setOrder] = useState(null);

  useEffect(() => {
    socket.onmessage = (event) => {
      const receivedOrder = JSON.parse(event.data);
      setOrder(receivedOrder);
    };
  }, []);

  return (
    <div>
      <h2>Cook</h2>
      {order && <p>Received order: {order}</p>}
    </div>
  );
}

export default Cook;
