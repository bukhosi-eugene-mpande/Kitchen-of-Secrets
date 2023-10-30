import React, { useState, useEffect, useRef } from 'react';

function ChatRoom() {
    const [messages, setMessages] = useState([]);
    const [message, setMessage] = useState('');
    const [socket, setSocket] = useState(null);
    const logRef = useRef(null);

    useEffect(() => {
        const sock = new WebSocket('ws://localhost:8000/ws');
        setSocket(sock);

        return () => {
            sock.close();
        };
    }, []);

    useEffect(() => {
        if (!socket) return;

        socket.onopen = () => {
            console.log('WebSocket connection opened');
        };

        socket.onerror = (e) => {
            console.log('WebSocket error:', e);
        };

        socket.onclose = () => {
            console.log('WebSocket connection closed');
        };

        socket.onmessage = (e) => {
            setMessages((messages) => [...messages, e.data]);
        };
    }, [socket]);

    useEffect(() => {
        if (logRef.current) {
            logRef.current.scrollTop = logRef.current.scrollHeight;
        }
    }, [messages]);

    const handleSendMessage = (e) => {
        e.preventDefault();

        socket.send(message);

        setMessage('');
    };

    return (
        <div>
            <ul ref={logRef} style={{ height: '200px', overflowY: 'scroll' }}>
                {messages.map((message, index) => (
                    <li key={index}>{message}</li>
                ))}
            </ul>
            <form onSubmit={handleSendMessage}>
                <input
                    type='text'
                    value={message}
                    onChange={(e) => setMessage(e.target.value)}
                />
                <button type='submit'>Send</button>
            </form>
        </div>
    );
}

export default ChatRoom;