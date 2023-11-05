import MeetTeam from '../assets/img/MeetTeam.jpg';
import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css'; // Import Bootstrap CSS
import { Card } from 'react-bootstrap'; // Import Bootstrap Card components

//team images
import Thato from '../assets/img/thato.jpg';

const teamMembers = [
  {
    name: 'Ashley Kapaso',
    role: 'Team Leader',
    image: '../assets/img/ashley.jpg',
  },
  {
    name: 'Ayanda Juqu',
    role: 'Team Leader',
    image: '../assets/img/ayanda.jpg',
  },
  {
    name: 'Joshua Wereley',
    role: 'Management System',
    image: '../assets/img/josh.jpg',
  },
  {
    name: 'Eugene Mpande',
    role: 'Team Leader',
    image: '../assets/img/eugene.jpg',
  },
  {
    name: 'Chenoa Perkett',
    role: 'Team Leader',
    image: '../assets/img/chenoa.jpg',
  },
  {
    name: 'Thato Kalagobe',
    role: 'Reservations & Frontend',
    image: Thato,
  },
];

const Team = () => {
  return (
    <div className="team" style={team}>
      <h2 className='mt-5'>Meet our Team</h2>
      <div className="team-container text-center justify-content-center container">
        <div className="card-deck row">
          {teamMembers.map((member, index) => (
            <Card className="col-3" key={index} style={{ backgroundColor: getCardBackgroundColor(member.name) }}>
              <div className="team-member-image" style={{ backgroundImage: `url(${member.image})` }}></div>
              <Card.Body>
                <Card.Title>{member.name}</Card.Title>
                <Card.Text>{member.role}</Card.Text>
              </Card.Body>
            </Card>
          ))}
        </div>
      </div>
    </div>
  );
};

const getCardBackgroundColor = (name) => {
  // Check if the name matches the conditions for purple background
  if (name === 'Eugene Mpanza' || name === 'Joshua Wereley') {
    return 'purple'; // Set the background color to purple
  }
  return ''; // Default background color
};

const team = {
  backgroundImage: `url(${MeetTeam})`,
  backgroundRepeat: 'no-repeat',
  backgroundSize: 'cover',
  height: '100vh',
  display: 'flex',
  flexDirection: 'column',
  flexWrap: 'wrap',
  alignItems: 'center',
  justifyContent: 'center',
};

export default Team;
